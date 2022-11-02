import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import javax.swing.text.html.HTMLDocument.HTMLReader.IsindexAction;

public class Main {
	
	public class Item implements Comparable{
		public int x,y,id,res;
		Item(){
			
		}
		public int compareTo(Object s){
			if(!(s instanceof Item))
				return -1;
			return x < ((Item)s).x ? -1 : (x == ((Item)s).x ? 0 : 1);
		}
	}
	public Item[] list;
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		list = new Item[n];
		for(int i=0;i<n;i++){
			list[i] = new Item();
			list[i].x = in.nextInt();
			list[i].y = in.nextInt();
			list[i].id = i;
		}
		Arrays.sort(list);
		int[] res =new int[n];
		ArrayList<Item> x = new ArrayList<Main.Item>();
		for(int i=n-1;i>=0;i--){
			list[i].res = 1;
			while(x.size() > 0 && list[i].x + list[i].y - 1 >= x.get(x.size()-1).x){
				list[i].res += x.get(x.size()-1).res;
				x.remove(x.size()-1);
			}
			res[list[i].id] = list[i].res;
			x.add(list[i]);
		}
		
		for(int i=0;i<n;i++){
			if(i>0) pw.print(" ");
			pw.print(res[i]);
		}
		pw.println("");
		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}