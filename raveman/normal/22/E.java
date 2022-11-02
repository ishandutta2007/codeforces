import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public int n;
	public int[] f;
	public int[] v;
	public boolean[] u;
	public int[] a;
	
	public int dfs(int ver){
		if(u[ver]){
			if(a[ver]==-1)
				return a[ver]=ver;
			return a[ver];
		}
		u[ver]=true;
		a[ver] = -1;
		return a[ver] = dfs(f[ver]);
	}

	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		n = in.nextInt();
		f = new int[n];
		v = new int[n];
		a = new int[n];
		u = new boolean[n];
		for(int i=0;i<n;i++){
			f[i] = in.nextInt()-1;
			v[f[i]] ++;
		}
		ArrayList<Integer> l1 = new ArrayList<Integer>();
		ArrayList<Integer> l2 = new ArrayList<Integer>();
		for(int i=0;i<n;i++)if(v[i]==0){
			int res = dfs(i);
			l1.add(i);
			l2.add(res);
		}
		for(int i=0;i<n;i++)if(!u[i]){
			dfs(i);
			l1.add(i);
			l2.add(i);
		}
		
		if(l1.size() == 1 && l1.get(0) == l2.get(0)) pw.println("0");
		else{
			pw.println(l1.size());
			for(int i=0;i<l1.size();i++)
				pw.println((l2.get(i)+1)+" "+(l1.get((i+1)%l1.size())+1));
		}

		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}