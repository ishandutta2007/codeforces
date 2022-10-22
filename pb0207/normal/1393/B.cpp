#include<bits/stdc++.h>
using namespace std;
 
const int N=1e5+1e3+7;
 
int n,q;

int vis[N],mp[N];

void inc(int x)
{
	if(vis[x]==3)
		mp[2]--;
	if(vis[x]==5)
		mp[4]--;
	if(vis[x]==7)
		mp[6]--;
	vis[x]++;
	if(vis[x]==2)
		mp[2]++;
	if(vis[x]==4)
		mp[4]++;
	if(vis[x]==6)
		mp[6]++;
	if(vis[x]==8)
		mp[8]++;
}

void dec(int x)
{
	if(vis[x]==2)
		mp[2]--;
	if(vis[x]==4)
		mp[4]--;
	if(vis[x]==6)
		mp[6]--;
	if(vis[x]==8)
		mp[8]--;
	vis[x]--;
	if(vis[x]==3)
		mp[2]++;
	if(vis[x]==5)
		mp[4]++;
	if(vis[x]==7)
		mp[6]++;
}

int main()
{
    scanf("%d",&n);
    int tot=0;
    for(int i=1;i<=n;i++)
    {
    	int x;
    	scanf("%d",&x);
    	inc(x);
    }
    scanf("%d",&q);
    while(q--)
    {
    	char op[2];
    	int x;
    	scanf("%s",op);
    	scanf("%d",&x);
    	if(op[0]=='+')
	    	inc(x);
    	else
    		dec(x);
    	if(mp[8])
    		puts("YES");
    	else if(mp[6])
    	{
    		if(mp[2]||mp[4]||mp[6]>=2)
    			puts("YES");
    		else
    			puts("NO");
    	}
    	else if(mp[4])
    	{
    		if(mp[2]>=2||mp[4]>=2)
    			puts("YES");
    		else
    			puts("NO");
    	}
    	else
    		puts("NO");
    }	 
}