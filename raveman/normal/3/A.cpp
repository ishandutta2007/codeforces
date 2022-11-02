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


string s1,s2;
int dist(string s1,string s2){
	return max(abs(s1[0]-'a'-(s2[0]-'a')),abs(s1[1]-'1'-(s2[1]-'1')));
}

string s3;

string move(){
	REP(i,8)REP(j,8){
		s3="";
		s3.pb(char('a'+i));
		s3.pb(char('1'+j));
		int x = dist(s2,s3);
		int y = dist(s1,s2);
		int z = dist(s1,s3);
		if(dist(s2,s3)==dist(s1,s2)-1 && dist(s1,s3)==1){
			string d = "";
			if(s3[0] < s1[0]) d.pb('L');
			if(s3[0] > s1[0]) d.pb('R');
			if(s3[1] < s1[1]) d.pb('D');
			if(s3[1] > s1[1]) d.pb('U');
			s1=s3;
			return d;
		}
	}
	return "FUCK";
}

int main(){
#ifdef LocalHost    
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif

	cin>>s1>>s2;
	cout<<dist(s1,s2)<<endl;
	while(s1!=s2){
		cout<<move()<<endl;
	}
    return 0;
}