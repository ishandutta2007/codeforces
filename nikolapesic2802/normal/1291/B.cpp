#include <iostream>
main()
{
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		int a[n];
		for(int i=0;i<n;i++)
			scanf("%i",&a[i]);
		bool ok=!(n%2==0&&a[n/2]==n/2-1&&a[n/2-1]==n/2-1);
		for(int i=0;i<n;i++)
			if(a[i]<std::min(i,n-1-i))
				ok=0;
		printf(ok?"Yes\n":"No\n");
	}
	return 0;
}