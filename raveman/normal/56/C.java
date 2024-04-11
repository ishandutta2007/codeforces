import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {
	public int pos,total;
	public String s;
	
	public ArrayList<String> go(){
		String name = "";
		while(Character.isLetter(s.charAt(pos))){
			name+=s.charAt(pos);
			pos++;
		}
		ArrayList<String> res = new ArrayList<String>();
		while(s.charAt(pos) != '.'){
			pos++;
			ArrayList<String> t = go();
			for(int i=0;i<t.size();i++)
				if(t.get(i).equals(name))
					total++;
			res.addAll(t);
		}
		
		pos++;
		res.add(name);
		return res;
	}
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		pos=0;total=0;
		s = in.next();
		go();
		
		pw.println(total);

		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}