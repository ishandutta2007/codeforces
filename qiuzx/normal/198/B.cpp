#include <bits/stdc++.h>
#define N 100010
using namespace std;
string s[2];
int n,k;
bool book[2][N]={};
void dfs(int wl,int wt,int he)
{
	int pos;
	if(he>=n)
	{
		cout<<"YES"<<endl;
		exit(0);
	}
	pos=he+k;
	if(pos>=n&&!book[!wl][pos])
	{
		cout<<"YES"<<endl;
		exit(0);
	}
	if(!book[!wl][pos]&&s[!wl][min(pos,n-1)]!='X')
	{
		book[!wl][pos]=true;
		dfs(!wl,wt+1,pos);
	}
	pos=he+1;
	if(pos>=n&&!book[wl][pos])
	{
		cout<<"YES"<<endl;
		exit(0);
	}
	if(!book[wl][pos]&&s[wl][min(pos,n-1)]!='X')
	{
		book[wl][pos]=true;
		dfs(wl,wt+1,pos);
	}
	pos=he-1;
	if(!book[wl][pos]&&s[wl][min(pos,n-1)]!='X'&&wt+1<pos)
	{
		book[wl][pos]=true;
		dfs(wl,wt+1,pos);
	}
}
int main(){
	cin>>n>>k;
	cin>>s[0]>>s[1];
	book[0][0]=true;
	dfs(0,-1,0);
	cout<<"NO"<<endl;
	return 0;
}