							/* in the name of Allah */
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define P pair<int, int>

int n, v, p[2];
P arr[2][100010];

bool cmp(P a, P b){
	return a > b;
}

int main(){
	int a, b;
	cin >> n >> v;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		arr[a-1][p[a-1]++] = P(b, i+1);
	}
	sort(arr[0], arr[0] + p[0], cmp);
	sort(arr[1], arr[1] + p[1], cmp);
	int cnt = 0, sum = 0, mx, idx1, idx2, mi1, mi2;
	for(idx2 = 0; cnt + 2 <= v && idx2 < p[1]; idx2++){
		cnt += 2;
		sum += arr[1][idx2].first;
	}
	for(idx1 = 0; cnt + 1 <= v && idx1 < p[0]; idx1++){
		cnt++;
		sum += arr[0][idx1].first;
	}
	mx = sum, mi1 = idx1, mi2 = idx2;
	for(int i = idx2 - 1, j = idx1; i >= 0 && j < p[0]; i--){
		sum = sum - arr[1][i].first + arr[0][j++].first;
		if(j < p[0])
			sum += arr[0][j++].first;
		if(sum > mx){
			mx = sum;
			mi2 = i;
			mi1 = j;
		}
	}
	cout << mx << endl;
	bool fir = true;
	for(int i = 0; i < mi1; i++){
		if(!fir)
			cout << ' ';
		fir = false;
		cout << arr[0][i].second;
	}
	for(int i = 0; i < mi2; i++){
		if(!fir)
			cout << ' ';
		fir = false;
		cout << arr[1][i].second;
	}
	cout << endl;
	return 0;
}

/*
5 4
2 5
2 10
1 4
1 4
1 2
*/