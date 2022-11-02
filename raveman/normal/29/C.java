import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	
	public ArrayList<Integer> res;
	public Map<Integer, ArrayList<Integer>> d;
	
	public void go(int ver,int prev){
		ArrayList<Integer> x = d.get(ver);
		for(int i=0;i<x.size();i++)
			if(x.get(i) != prev)
				go(x.get(i), ver);
		res.add(ver);
	}
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		d = new HashMap<Integer, ArrayList<Integer>>();
		int n = in.nextInt();
		for(int i=0;i<n;i++)
		{
			int a = in.nextInt();
			int b = in.nextInt();
			
			if(!d.containsKey(a))
				d.put(a, new ArrayList<Integer>());
			if(!d.containsKey(b))
				d.put(b, new ArrayList<Integer>());
			ArrayList<Integer> x = d.get(a);
			x.add(b);
			d.put(a,x);
			x = d.get(b);
			x.add(a);
			d.put(b, x);
		}
		
		Iterator it = d.entrySet().iterator();
		int start = -1;
		while(it.hasNext()){
			Entry<Integer, ArrayList<Integer>> curr = (Entry<Integer, ArrayList<Integer>>)it.next();
			if(curr.getValue().size() == 1){
				start = curr.getKey();
				break;
			}			
		}
		res = new ArrayList<Integer>();
		go(start, -1);
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