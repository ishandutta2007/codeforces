#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define N 1000010
using namespace std;
int a,b,k,l,r,mid,prime[N]={};
queue<int> pr;
int main(){
	bool flag=false;
	int i,j,ans=-1;
	cin>>a>>b>>k;
	for(i=2;i<N;i++)
		prime[i]=true;
	for(i=2;i*i<N;i++)
	{
		if(!prime[i])
			continue;
		for(j=i*i;j<N;j+=i)
			prime[j]=false;
	}
	pr.push(a-1); 
	for(i=a;i<=b;i++)
	{
		if(prime[i])
			pr.push(i);
		while(k<pr.size())
			pr.pop();
		if(pr.size()==k)
			ans=max(ans,i-pr.front()+1);
	}
	if(pr.front()==a-1)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}