import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		int res = 0;
		
		for(int i=0;i<n;i++){
			String s = in.next();
			boolean isDigit = true;
			for(int j=0;j<s.length();j++)
				isDigit &= Character.isDigit(s.charAt(j));
			if(isDigit && s.length() <= 2){
				int val = 0;
				for(int j=0;j<s.length();j++)
					val = val * 10 + s.charAt(j) - '0';
				if(val<18) res ++;
			}else{
				String[] list = {"ABSINTH", "CHAMPAGNE","TEQUILA","WHISKEY","WINE","VODKA","SAKE","RUM","GIN","BRANDY","BEER"};
				for(int j=0;j<list.length;j++)
					if(list[j].equals(s))
						res++;
			}
		}
		
		pw.println(res);

		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}