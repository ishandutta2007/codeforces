#include<bits/stdc++.h>

using namespace std;

void kill(set<int> &st,int tg,int n){
	st.erase(tg);
	st.erase(n+tg);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	vector<bool> fl(n,false);
	queue<int> qu;
	int d=0,r=0;
	set<int> ds,rs;
	for(int i=0;i<n;i++){
		qu.push(i);
		if(s[i]=='D'){
			d++;
			ds.insert(i);
			ds.insert(n+i);
		}
		else{
			r++;
			rs.insert(i);
			rs.insert(n+i);
		}
	}
	while(d>0 && r>0){
		int od=qu.front();
		qu.pop();
		if(fl[od]){continue;}
		qu.push(od);
		if(s[od]=='D'){
			int tg=(*rs.lower_bound(od))%n;
			fl[tg]=true;
			r--;
			kill(rs,tg,n);
		}
		else{
			int tg=(*ds.lower_bound(od))%n;
			fl[tg]=true;
			d--;
			kill(ds,tg,n);
		}
	}
	if(d>0){cout << "D\n";}
	else{cout << "R\n";}
  return 0;
}