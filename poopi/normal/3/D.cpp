					/* in the name of Allah */
#include<iostream>
#include<queue>
#include<string>
#include<map>
using namespace std;

#define int64 long long
#define P pair<int64, int>

int n, m;
char in[60000];
int idx[60000];
int64 arr[60000][2];
int sum[60000], mn[60000];
priority_queue <P> q;

bool hasErr(){
	int f = 0, s = 0, q = 0;
	for(int i = 0; i < n; i++){
		if(in[i] == '(') f++;
		if(in[i] == ')') s++;
		if(in[i] == '?') q++;
	}
	if(abs(f - s) > q)
		return true;
	int t = (n - 2 * max(f, s)) / 2;
	if(f < s) t += s - f;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(in[i] == '(') cnt++;
		else if(in[i] == ')') cnt--;
		else (cnt += (t-- > 0) ? 1 : -1);
		if(cnt < 0) return true;
	}
	return cnt != 0;
}

int main(){
	gets(in);
	n = strlen(in);
	for(int i = 0; i < n; i++){
		if(in[i] == '?'){
			idx[m] = i;
			cin >> arr[m][0] >> arr[m][1];
			m++;
		}
	}
	if(n % 2 || hasErr()){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++)
		if(in[i] == '?')
			in[i] = '(';
	sum[0] = 1;
	for(int i = 1; i < n; i++)
		sum[i] = sum[i-1] + (in[i] == '(' ? 1 : -1);
	mn[n-1] = sum[n-1] / 2;
	for(int i = n - 2; i >= 0; i--)
		mn[i] = min(sum[i] / 2, mn[i+1]);
	int cnt = 0;
	for(int i = 0; i < m; i++){
		if(mn[idx[i]] > cnt){
			in[idx[i]] = ')';
			cnt++;
		}
	}
	//puts(in);
	for(int i = m - 1; i >= 0; i--){
		if(in[idx[i]] == '(')
			q.push(P(arr[i][0] - arr[i][1], i));
		else if(!q.empty() && q.top().first > arr[i][0] - arr[i][1]){
			P t = q.top();
			in[idx[i]] = '(';
			in[idx[t.second]] = ')';
			q.pop();
			q.push(P(arr[i][0] - arr[i][1], i));
		}
	}
	int64 res = 0;
	for(int i = 0; i < m; i++)
		res += (in[idx[i]] == '(' ? arr[i][0] : arr[i][1]);
	cout << res << endl;
	puts(in);
	return 0;
}