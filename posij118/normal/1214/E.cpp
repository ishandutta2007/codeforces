#include<algorithm>
#include<vector>
#include<iostream>
using namespace std; 

int main(){
		int n;
		cin >> n;

		vector<int> a(n);
		int b[n];
		int p[2*n];
		for(int i = 0; i<n; i++){
			p[i] = 2*i;
			p[i + n] = 2*i + 1;
		}

		pair<int, int> srt[n];
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			srt[i] = {x, i};
		}

		sort(srt, srt + n);
		reverse(srt, srt + n);

		for(int i = 0; i<n; i++){
			a[i] = srt[i].second;

			int x = a.size();
			if(i + srt[i].first == x){
				a.push_back(srt[i].second + n);
				b[srt[i].second] = -1;
			}

			else{
				b[srt[i].second] = i + srt[i].first - 1;
			}
		}

		for(int i = 0; i<a.size() - 1; i++){
			cout << p[a[i]] + 1 << " " << p[a[i + 1]] + 1 << endl;
		}

		for(int i = 0; i<n; i++){
			if(b[i] != -1) cout << p[a[b[i]]] + 1 << " " << p[i + n] + 1 << endl;
		}
}