					/* in the name of Allah */
#include <iostream>
#include <string>

using namespace std;

int n;
string str, inp;
int cnt[1010];
bool mark[1010][1010];
int res[1010];
int tmp[1010];
int main(){
	while(cin >> n >> inp){
		str = "";
		for(int i = 0; i < inp.length(); i++)
			if(inp[i] != '=')
				str += inp[i];
		n = str.length() + 1;
		for(int i = 0; i < n - 1; i++){
			if(str[i] == 'L'){
				cnt[i]++;
				mark[i][i+1] = true;
			}
			if(str[i] == 'R'){
				cnt[i+1]++;
				mark[i+1][i] = true;
			}
		}
		int p = 1, rem = n;
		while(rem){
			memset(tmp, 0, sizeof tmp);
			for(int i = 0; i < n; i++){
				if(res[i] != 0 || cnt[i] > 0) continue;
				res[i] = p;
				rem--;
				if(i > 0 && mark[i-1][i])
					tmp[i-1]--;
				if(i < n - 1 && mark[i+1][i])
					tmp[i+1]--;
			}
			for(int i = 0; i < n; i++)
				cnt[i] += tmp[i];
			p++;
		}
		p = 0;
		cout << res[0];
		for(int i = 0; i < inp.length(); i++){
			if(inp[i] == '=')
				cout << ' ' << res[p];
			else cout << ' ' << res[++p];
		}
		cout << endl;
	}
	return 0;
}