#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn = 200;
char s[maxn];
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	int z = 1;
	for(int i = 1; i < n; ++i) if(s[i] == '1') z = 0;
	int ans;
	if(n&1){
        if(z) ans = (n+1)/2 - 1;
        else ans = (n+1)/2;
	}
	else {
        ans = (n+1)/2;
	}
	cout<<ans<<endl;
}