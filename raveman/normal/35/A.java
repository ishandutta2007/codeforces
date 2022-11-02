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
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(new  File("output.txt"));
		
		int x = in.nextInt();
		for(int i=0;i<3;i++){
			int a = in.nextInt();
			int b = in.nextInt();
			if(a==x) x = b;
			else if(b==x) x = a;
		}
		pw.println(x);

		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}