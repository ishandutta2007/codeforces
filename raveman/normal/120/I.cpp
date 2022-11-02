#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int nb(int x){return x==0?0:1+nb(x&(x-1));}
const int ALL = (1<<7)-1;
int TEMP[]={
	ALL ^ (1<<3),
	(1<<2)|(1<<5),
	ALL ^ (1<<1) ^ (1<<5),
	ALL ^ (1<<1) ^ (1<<4),
	ALL ^ (1<<0) ^ (1<<4) ^ (1<<6),
	ALL ^ (1<<2) ^ (1<<4),
	ALL ^ (1<<2),
	(1<<0) | (1<<2) | (1<<5),
	ALL,
	ALL ^ (1<<4)
};
int a[10][10];
int n;

char _s[222222];
int b[222222];
int m[222222];
int w[222222];

int getScore(int pos,int i){
	int curr_score=0;
	if(pos+n/2<=i)
		curr_score += a[b[pos]][b[pos+n/2]];
	else if(pos<=i) curr_score += nb(TEMP[b[pos]]);
	else curr_score += 7;
	return curr_score;
}

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost
	freopen("output.txt","w",stdout);
#endif
	REP(i,10)REP(j,10) a[i][j]=nb(TEMP[i]&TEMP[j]);
	gets(_s);n=strlen(_s);
	REP(i,n) b[i]=_s[i]-'0';
	REP(i,n/2) m[i] = (i?m[i-1]:0)+nb(TEMP[b[i]]);
	REP(i,n/2) w[i] = (i?w[i-1]:0)+a[b[i]][b[i+n/2]];
	
	int score = 0;
	REP(i,n/2) score += a[b[i]][b[i+n/2]];
	bool found = 0;
	for(int i=n-1;i>=0;i--){
		for(int j=b[i]+1;j<=9;j++){
			b[i] = j;

			int max_score = 0;
			if(i>=n/2){
				max_score = i-n/2-1>=0?w[i-n/2-1]:0;
				max_score += a[b[i-n/2]][b[i]];
				max_score += m[n/2-1] - m[i-n/2];
			}else{
				max_score = i-1>=0?m[i-1]:0;
				max_score += nb(TEMP[j]);
				max_score += 7 * (n/2-i-1);
			}
			
			if(max_score>score){
			
				int curr_score = 0;
				REP(pos,n/2) curr_score += getScore(pos, i);
				

				FOR(pos,i+1,n){
					REP(j,10){
						max_score = curr_score;

						max_score -= getScore(pos%(n/2), pos-1);
						b[pos]=j;
						max_score += getScore(pos%(n/2), pos);

						if(max_score>score) {curr_score=max_score;break;}
					}

				}
				REP(k,n) printf("%d",b[k]);
				puts("");
				return 0;
			}
		}
	}
	
	puts("-1");

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}