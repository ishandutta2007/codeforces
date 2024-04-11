import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	

	public class Seg implements Comparable {
		public int x,y;
		public int compareTo(Object s){
			if(!(s instanceof Seg))
				return -1;
			if(y==((Seg)s).y) return 0;
			if(y<((Seg)s).y) return -1;
			return 1;
		}
	}
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		Seg[] a = new Seg[n];
		for(int i=0;i<n;i++){
			a[i] = new Seg();
			a[i].x = in.nextInt();
			a[i].y = in.nextInt();
			if(a[i].x > a[i].y){
				int c = a[i].x;
				a[i].x=a[i].y;
				a[i].y=c;
			}
		}
		Arrays.sort(a);
		
		ArrayList<Integer> res =new ArrayList<Integer>();
		
		int end = -1000000000;
		for(int i=0;i<a.length;i++){
			if(a[i].x > end){
				res.add(a[i].y);
				end = a[i].y;
			}
		}
		
		pw.println(res.size());
		for(int i=0;i<res.size();i++){
			if(i>0) pw.print(" ");
			pw.print(res.get(i));
		}
		pw.println();
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}