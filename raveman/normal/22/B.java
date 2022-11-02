import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		String[] s = new String[n];
		for(int i=0;i<n;i++)
			s[i] = in.next();
		
		int res = 0;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int x=i;x<n;x++)
					for(int y=j;y<m;y++)if(res < (x-i)*2 + (y-j)*2 + 4){
						boolean good = true;
						
						for(int q=i;q<=x;q++){
							for(int w=j;w<=y;w++)
								if(s[q].charAt(w)!='0'){
									good=false;
									break;
								}
							if(!good)
								break;
						}
						
						if(good) res =  (x-i)*2 + (y-j)*2 + 4;
					}
		
		pw.println(res);

		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}