#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXL=100011;
const int MAXM=100011;

inline string enCode(int v){
	return (v)?"Alice":"Bob";
}

string input;
int L, M;
int Str[MAXL];

int Cnt[MAXL][26];
vector<int> Cp[26];
vector<int> Val[26];
int Pre[26][MAXL], Suf[26][MAXL];

struct Query{
	int l, r, c, p;
	Query(){}
	Query(int _l, int _r, int _c, int _p){l=_l;r=_r;c=_c;p=_p;}
} Q[MAXL];

int Qc;

bool operator < (Query A, Query B){
	return A.r-A.l<B.r-B.l;
}

int Slow_Deal(int l, int r, int d=0){
	if(l==r)	return 1;
	if(d<0 && Pre[Str[l-1]][r]>=0)	return Pre[Str[l-1]][r];
	if(d>0 && Suf[Str[r+1]][l]>=0)	return Suf[Str[r+1]][l];
	bool ___[27];
	for(int i=0;i<27;++i)	___[i]=false;
	for(int c=0, lc, rc, _;c<26;++c){
		lc=Cnt[l-1][c], rc=Cnt[r][c];
		if(lc==rc)	continue;
		_=0;
		for(int p=lc+1;p<rc;++p)
			_^=Val[c][p];
		_^=Slow_Deal(l, Cp[c][lc]-1, 1);
		_^=Slow_Deal(Cp[c][rc-1]+1, r, -1);
		if(_<27)	___[_]=true;
	}
	int ret;
	for(int i=0;i<27;++i)	if(!___[i])	{ret=i;break;}
	if(d<0)	Pre[Str[l-1]][r]=ret;
	if(d>0)	Suf[Str[r+1]][l]=ret;
	return ret;
}

int Quick_Deal(int l, int r, int d=0){
	if(l==r)	return 1;
	if(d<0 && Pre[Str[l-1]][r]>=0)	return Pre[Str[l-1]][r];
	if(d>0 && Suf[Str[r+1]][l]>=0)	return Suf[Str[r+1]][l];
	bool ___[27];
	for(int i=0;i<27;++i)	___[i]=false;
	for(int c=0, lc, rc, _;c<26;++c){
		lc=Cnt[l-1][c], rc=Cnt[r][c];
		if(lc==rc)	continue;
		_=Val[c][rc-1]^Val[c][lc];
		_^=Quick_Deal(l, Cp[c][lc]-1, 1);
		_^=Quick_Deal(Cp[c][rc-1]+1, r, -1);
		if(_<27)	___[_]=true;
	}
	int ret;
	for(int i=0;i<27;++i)	if(!___[i])	{ret=i;break;}
	if(d<0)	Pre[Str[l-1]][r]=ret;
	if(d>0)	Suf[Str[r+1]][l]=ret;
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> input;
	L=input.length();
	for(int i=1;i<=L;++i)	Str[i]=input[i-1]-'a';
	
	for(int i=1;i<=L;++i){
		for(int c=0;c<26;++c)	Cnt[i][c]=Cnt[i-1][c];
		++Cnt[i][Str[i]];
		Cp[Str[i]].push_back(i);
	}
	
	for(int i=0;i<26;++i)
		for(int j=1;j<=L;++j)	Pre[i][j]=Suf[i][j]=-1;
	
	for(int i=0;i<26;++i){
		for(int p=0, s=Cp[i].size();p<s;++p)	Val[i].push_back(0);
		for(int p=1, s=Cp[i].size();p<s;++p){
			Q[++Qc]=Query(Cp[i][p-1]+1, Cp[i][p]-1, i, p);
		}
	}
	
	sort(Q+1, Q+Qc+1);
	
	for(int q=1;q<=Qc;++q)
		Val[Q[q].c][Q[q].p]=Slow_Deal(Q[q].l, Q[q].r);
	
	for(int i=0;i<26;++i)
		for(int p=1, s=Val[i].size();p<s;++p)
			Val[i][p]^=Val[i][p-1];
	
	cin >> M;
	
	for(int i=1, a, b;i<=M;++i){
		cin >> a >> b;
		cout << enCode(Quick_Deal(a, b)) << endl;
	}
	
	return 0;
}