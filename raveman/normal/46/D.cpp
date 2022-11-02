#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

map<int,int> m;
bool u[111111];


int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	int l,b,f,n;
	cin>>l>>b>>f>>n;
	int len[111];
	REP(i,n){
		int x,y;
		scanf("%d %d",&x,&y);
		len[i+1]=y;
		if(x==1){
			for(int j=0;j<l;)if(u[j]==0){
				int k = j;
				while(k<l && !u[k]) k++;

				if(j==0 && k==l){
					if(y<=l){
						m[i+1]=0;
						REP(q,y) u[q]=1;
						break;
					}
				}else if(j==0){
					if(y+f<=k){
						m[i+1]=0;
						REP(q,y) u[q]=1;
						break;
					}
				}else if(k==l){
					if(y+b<=k-j){
						int pos = j + b;
						m[i+1]=pos;
						REP(q,y) u[pos+q]=1;
						break;
					}
				}else{
					if(y+b+f<=k-j){
						int pos = j + b;
						m[i+1]=pos;
						REP(q,y) u[pos+q]=1;
						break;
					}
				}

				j=k;
			}else j++;

			if(m.count(i+1)) cout<<m[i+1]<<endl;
			else cout<<-1<<endl;
		}else{

			int pos = m[y];
			REP(j,len[y]) u[pos+j]=0;
		}
	}

	return 0;
}