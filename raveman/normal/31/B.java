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

	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		String s = in.next();
		ArrayList<String> a = new ArrayList<String>();
		
		boolean shit = false;
		for(int i=0;i<s.length();){
			int j = i;
			if(!Character.isLetter(s.charAt(i))){
				shit=true;
				break;
			}
			while(j<s.length() && Character.isLetter(s.charAt(j))) j++;
			if(j==s.length()){
				shit=true;
				break;
			}
			j++;
			if(j==s.length() || !Character.isLetter(s.charAt(j))){
				shit=true;
				break;
			}
			boolean has = false;
			for(int k=j;k<s.length();k++)
				if(s.charAt(k)=='@'){has=true;}
			j++;
			if(!has) j = s.length();
			a.add(s.substring(i, j));
			i=j;
		}
		
		if(shit)pw.println("No solution");
		else{
			for(int i=0;i<a.size();i++){
				if(i>0) pw.print(",");
				pw.print(a.get(i));
			}
			pw.println();
		}
		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}