#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF 1<<30

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int H,D,C,N;
	int hh,mm;
	cin>>hh>>mm;
	cin>>H>>D>>C>>N;
	double cost;
	int buns;
	if(hh>=20){
	    buns = (H%N?H/N+1:H/N);
		cost = (double)((double)buns*(double)C*(double)(0.8));
	
	    cout<<std::setprecision(5)<<cost;
	}
	else{
	    buns = (H%N?H/N+1:H/N);
		double c = (double)(buns*C);
		double c1;
		hh++;
		H+=((60-mm)*D);
		if(hh<20){
			H+=(60*(20-hh)*D);
		}
		buns = (H%N?H/N+1:H/N);
		c1 = (double)((double)buns*(double)C*(double)(0.8));
		if((c-c1)>0)
			cout<<std::setprecision(9)<<c1;
		else
			cout<<std::setprecision(9)<<c;
	}
}