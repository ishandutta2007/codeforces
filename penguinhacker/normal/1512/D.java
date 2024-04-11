import java.util.*;
import java.io.*;
public class CF {
    
   static void shuffleArray(int[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            int tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }   
    }
    
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int q = Integer.parseInt(st.nextToken());
		while(q-->0) {
			int n = Integer.parseInt(br.readLine())+2;
			int[] arr = new int[n];
			st = new StringTokenizer(br.readLine());
			for (int i=0; i<n; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			shuffleArray(arr);
			Arrays.sort(arr);
			long sum = 0;
			for (int i=0; i<n-1; i++) {
				sum+=arr[i];
			}
			boolean reached = false;
			int dex = -1;
			for (int i=0; i<n-1; i++) {
				if (sum-arr[i]==arr[n-1]) {
					reached = true;
					dex = i;
				}
			}
			if (!reached) {
				if (sum-arr[n-2]==arr[n-2]) {
					for (int i=0; i<n-2; i++) {
						System.out.print(arr[i]+" ");
					}
					System.out.println();
				}
				else {
					System.out.println(-1);
				}
			}
			else {
				for (int i=0; i<n-1; i++) {
					if (i==dex) {
						continue;
					}
					System.out.print(arr[i]+" ");
				}
				System.out.println();
			}
		}	
	}
}