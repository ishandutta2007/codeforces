import java.util.*;  
public class Main {
	public static void main(String[] args) {
		int n,m,z,a,b,ans;
		Scanner in=new Scanner(System.in);
		n=in.nextInt();
		m=in.nextInt();
		z=in.nextInt();
		a=n;
		b=m;
		ans=0;
		for(;a<=z&&b<=z;){
			if(a==b)ans++;
			if(a<b)a+=n;else b+=m;
		}
		System.out.println(ans);
	}
}