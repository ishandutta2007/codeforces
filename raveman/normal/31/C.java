import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public class Obj implements Comparable<Obj> {
		public int x,y,id;
		public Obj(int _x,int _y,int _id){
			x = _x;
			y = _y;
			id=_id;
		}
		
		public int compareTo(Obj xx){
			return y - xx.y;
		}
	}
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		Obj[] x = new Obj[n];
		for(int i=0;i<n;i++)
			x[i] = new Obj(in.nextInt(),in.nextInt(),i+1);
		Arrays.sort(x);
		ArrayList<Integer> res =new ArrayList<Integer>();
		for(int i=0;i<n;i++){
			boolean good = true;
			
			int end = -1;
			for(int j=0;j<n;j++)if(j!=i){
				if(x[j].x < end) {good=false;break;}
				end = x[j].y;
			}
			
			if(good) res.add(x[i].id);
		}
		Collections.sort(res);
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