import java.io.File;
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
import java.util.Set;
import java.util.SortedMap;
import java.util.TreeMap;

import javax.swing.Icon;

public class Main {
	public class Item implements Comparable<Item>{
		public int l,h;
		public boolean r;
		public Item(){}
		public int compareTo(Item s){
			if(l==s.l) return 0;
			return l<s.l ? -1 : 1;
		}
	}
	public void run () throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(new  File("output.txt"));

		int n = in.nextInt();
		Item[] w = new Item[2*n];
		for(int i=0;i<n;i++){
			int h=in.nextInt();
			int l=in.nextInt();
			int r=in.nextInt();

			Item q2 = new Item();
			q2.l = r;
			q2.h = h;
			q2.r = false;
			w[2*i+1]=q2;
			
			Item q = new Item();
			q.r = true;
			q.l = l;
			q.h = h;
			w[2*i]=q;
		}
		
		int[] x = new int[4*n];
		int[] y= new int[4*n];
		int res=0;
		
		Arrays.sort(w);
		
		TreeMap<Integer, Integer> s = new TreeMap<Integer, Integer>();
		int last_y=0;
		for(int i=0;i<2*n;){
			int j = i;
			while(j<2*n && w[j].l == w[i].l){
				int val = s.containsKey(w[j].h) ? s.get(w[j].h) : 0;
				if(w[j].r){
					s.put(w[j].h, val+1);
				}else{
					if(val==1) s.remove(w[j].h);
					else s.put(w[j].h, val-1);
				}
				j++;
			}
			
			int max_y = 0;
			if(s.size()>0){
				max_y = s.lastKey();
			}
			
			if(max_y != last_y){
				x[res]=(w[i].l);
				y[res]=(last_y);
				res++;
				x[res]=(w[i].l);
				y[res]=(max_y);
				res++;
				
				last_y=max_y;
			}
			i=j;
		}
		
		
		pw.println(res);
		for(int i=0;i<res;i++)
			pw.println(x[i]+" "+y[i]);

		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}