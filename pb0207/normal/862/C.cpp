#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;


int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	if(!x&&n==2)return 0*printf("NO");
	else if(!x&&n%4==2){
		printf("YES\n");
		for(int i=1;i+4<=n-4;i+=4)cout<<i+100001<<" "<<i+100002<<" "<<i+100003<<" "<<i+100004<<" ";
		cout<<(3<<3)<<" "<<(3<<1)<<" "<<1<<" "<<3<<" "<<(3<<2)<<" "<<(1<<4);
		return 0;
	}
//	1 2 3 4 5 6
	printf("YES\n");
	for(int i=1;i+4<=n;i+=4)cout<<i+100001<<" "<<i+100002<<" "<<i+100003<<" "<<i+100004<<" ";
	if(n%4==1)	cout<<x;
	else if(n%4==2)cout<<x+(1<<18)<<" "<<(1<<18);
	else if(n%4==3)cout<<x+(1<<18)<<" "<<(1<<19)<<" "<<((1<<18)+(1<<19));
	else if(n%4==0)cout<<x<<" "<<(1<<18)<<" "<<(1<<19)<<" "<<((1<<18)+(1<<19));
}