#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5 + 85 - 69;
int last[maxn], nexxt[maxn];
int a[maxn], n;
vector<int> v, w;

int Next(int id){
	return (id == n or nexxt[id] == id) ? id : nexxt[id] = Next(nexxt[id]);
}

int Last(int id){
	return (id == -1 or last[id] == id) ? id : last[id] = Last(last[id]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v.reserve(maxn);
	w.reserve(maxn);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		nexxt[i] = last[i] = i;
		if(a[i] < a[i - 1])
			v.PB(i);
	}
	nexxt[n] = last[n] = n;
	int time = 0;
	while(v.size()){
		time++;
		w.clear();
		for(auto id : v){
			nexxt[id] = id + 1;
			last[id] = id - 1;
		}
		for(auto id : v)
			if(Next(id) != n and Last(id) != -1 and a[Next(id)] < a[Last(id)])
				w.PB(Next(id));
		v = w;
	}
	cout << time << endl;
	return 0;
}