#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF (1<<30)

using namespace std;

int A[100001];
int Max(int i){
	return max(max(max(A[i],A[i-1]),max(A[i-2],A[i-3])),A[i-4]);
}
int Min(int i){
	return min(min(min(A[i],A[i-1]),min(A[i-2],A[i-3])),A[i-4]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string s;
	string temp;
	for (int i = 1; i <= n; ++i)
	{
		cin>>A[i];
	}
	cin>>s;
	s="a"+s;
	int count = 4;
	std::vector<int> nochange,change;
	for (int i = 5; i <= n; ++i)
	{
		if(count>=4){
			if(s[i] == s[i-1]){
				nochange.pb(i);
			}
			else{
				change.pb(i);
				count=0;
			}
		}
		else if(s[i]==s[i-1]){
			count++;
		}
	}
	int csize=change.size();
	int nsize = nochange.size();
	int l=-1000000000,r=1000000000;
	int ltemp,rtemp;
	for(int i=0;i<csize;i++){
		

		int pos = change[i];
		if(s[pos]=='1'){
			ltemp=1;
			ltemp+=Max(pos);
			if(l<ltemp){
				l=ltemp;
			}
		}	
		else{
			rtemp=-1;
			rtemp+=Min(pos);
			if(r>rtemp){
				r=rtemp;
			}
		}
	}/*
	int temp;
	for(int i=0;i<nsize;i++){
		int pos=nochange[i];
		if(s[pos]=='1'){
			temp=Min(i);
			if(ltemp)
		}
		else{

		}
	}*/
		cout<<l<<" "<<r<<"\n";

}