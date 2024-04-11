#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define F first
#define S second
const int mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	ll cont[n+5] = {};
	f(n){
		cin >> cont[i];
		if(!cont[i]){
			n--;
			i--;
		}
	}
	if(n>128){
		cout<<3<<endl;
		exit(0);
	}
	else{
		ll d[n+5][n+5]={};
		ll w[n+5][n+5]={};
		f(n){
			fr(j,0,n){
				d[i][j]=w[i][j]=1e9;
			}
		}
		ll weight = 1e9;
		f(n){
			fr(j,i+1,n){
				if(cont[i]&cont[j]){
					w[i][j]=w[j][i]=1;
					d[i][j]=d[j][i]=1;
				}
			}
		}
		for (int k=0; k<n; ++k)    	{
	        for (int i=0; i<k; ++i)
	            for (int j=0; j<k; ++j)
	                if (i != j)
	                    if (w[k][i] + d[i][j] + w[j][k] < weight)
	                        weight = w[k][i] + d[i][j] + w[j][k];
	 
	        for (int i=0; i<n; ++i)
	            for (int j=0; j<n; ++j)
	                if (d[i][k] + d[k][j] < d[i][j])
	                    d[i][j] = d[i][k] + d[k][j];
	    }
	    if(weight>=1e9){
	    	cout<<-1<<endl;
	    }
	    else{
	    	cout<<weight<<endl;
	    }
	}
	
}