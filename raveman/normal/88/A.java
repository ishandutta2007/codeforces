import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;
		
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);

            String x[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
            String y[] = new String[3];
            for(int i=0;i<3;i++)
            	y[i] = in.next();
            Arrays.sort(y);
            for(int i1=0;i1<3;i1++)
            	for(int i2=0;i2<3;i2++)if(i1!=i2)
            		for(int i3=0;i3<3;i3++)if(i1!=i3 && i1!=i3){
            			int p1 = -1;
            			int p2 = -1;
            			int p3 = -1;
            			for(int j=0;j<12;j++){
            				if(y[i1].equals(x[j])) p1=j;
            				if(y[i2].equals(x[j])) p2=j;
            				if(y[i3].equals(x[j])) p3=j;
            			}
            			if(p2<p1) p2+=12;
            			while(p3<p2) p3+=12;
            			if(p2==p1+4 && p3==p2+3){
            				pw.println("major");
            				pw.close();
            				return;
            			}
            			if(p2==p1+3 && p3==p2+4){
            				pw.println("minor");
            				pw.close();
            				return;
            			}
            		}
            pw.println("strange");
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}