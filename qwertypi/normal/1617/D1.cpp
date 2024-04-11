#include <bits/stdc++.h>
 
using namespace std;
 
struct Tuple{
	int a, b, c;
};
 
vector<Tuple> I, C;
 
int qry(int a, int b, int c){
	cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
	int v; cin >> v;
	return v; 
}
 
void answer(vector<int> ans){
	cout << "! " << ans.size() << ' ';
	for(auto i : ans){
		cout << i + 1 << ' ';
	}
	cout << endl;
	return;
}
 
vector<int> rI, rC;
 
int check(int v, int other = -1){
	assert(!rI.empty() && !rC.empty());
	int res = qry(v, rI[0], rC[0]);
	if(res){
		rC.push_back(v);
		if(other != -1) rI.push_back(other);
	}else{
		rI.push_back(v);
		if(other != -1) rC.push_back(other);
	}
	return res;
}
 
void solve(){
	I.clear(); C.clear();
	rI.clear(); rC.clear();
	int n;
	cin >> n;
	for(int i = 0; i < n / 3; i++){
		int v = qry(i * 3, i * 3 + 1, i * 3 + 2);
		if(v == 0){
			I.push_back({i * 3, i * 3 + 1, i * 3 + 2});
		}else{
			C.push_back({i * 3, i * 3 + 1, i * 3 + 2});
		}
	}
	assert(I.size() != 0);
	assert(C.size() != 0);
	int res[3] = {0, 0, 0};
	res[0] = qry(I[0].a, I[0].b, C[0].a);
	res[1] = qry(I[0].a, I[0].b, C[0].b);
	res[2] = qry(I[0].a, I[0].b, C[0].c);
	if(res[0] == 0 && res[1] == 0 && res[2] == 0){
		rI.push_back(I[0].a);
		rI.push_back(I[0].b);
		res[0] = qry(I[0].a, C[0].a, C[0].b);
		res[1] = qry(I[0].a, C[0].b, C[0].c);
		res[2] = qry(I[0].a, C[0].c, C[0].a);
		if(!res[0] && !res[1]){
			rC.push_back(C[0].a);
			rI.push_back(C[0].b);
			rC.push_back(C[0].c);
		}else if(!res[1] && !res[2]){
			rC.push_back(C[0].a);
			rC.push_back(C[0].b);
			rI.push_back(C[0].c);
		}else if(!res[2] && !res[0]){
			rI.push_back(C[0].a);
			rC.push_back(C[0].b);
			rC.push_back(C[0].c);
		}else{
			rC.push_back(C[0].a);
			rC.push_back(C[0].b);
			rC.push_back(C[0].c);
		}
		check(I[0].c);
	}else{
		rI.push_back(I[0].c);
		(res[0] ? rC.push_back(C[0].a) : rI.push_back(C[0].a));
		(res[1] ? rC.push_back(C[0].b) : rI.push_back(C[0].b));
		(res[2] ? rC.push_back(C[0].c) : rI.push_back(C[0].c));
		check(I[0].a, I[0].b);
	}
	
	for(int i = 1; i < (int) C.size(); i++){
		if(qry(C[i].a, C[i].b, rI[0])){
			rC.push_back(C[i].a);
			rC.push_back(C[i].b);
			check(C[i].c); 
		}else{
			rC.push_back(C[i].c);
			check(C[i].a, C[i].b);
		}
	}
	
	for(int i = 1; i < (int) I.size(); i++){
		if(!qry(I[i].a, I[i].b, rC[0])){
			rI.push_back(I[i].a);
			rI.push_back(I[i].b);
			check(I[i].c); 
		}else{
			rI.push_back(I[i].c);
			check(I[i].a, I[i].b);
		}
	}
	
	answer(rI); 
}
 
int main(){
	int t;
	cin >> t;
	while(t--) solve();
}