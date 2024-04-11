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

public class Main {
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		String s = in.next();
		
		for(int i=0;i<s.length();){
			if(s.charAt(i) == '.') pw.print(0);
			else{
				i++;
				if(s.charAt(i) == '.') pw.print(1);
				else pw.print(2);
			}
			i++;
		}

		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}