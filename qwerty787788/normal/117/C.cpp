#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
//#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433832795
//
int n;
char c;
char a[5000][5000];
int color [5000];
vector <int> st;
bool find1 = false;
//
void dfs(int k) {
	if (!find1) {
	color[k] = 1; 
	st.push_back(k);
	for (int i = 0; i < n; i ++) if (!find1){
		if (a[k][i] == '1') {
			if (color[i] == 0) {if (!find1) dfs(i);} else if ((color[i]==1)&&(!find1)){
				int start = 0;
				while ((start < st.size())&&(st[start] != i)) start++;
				while (st.size()-start > 3) {
					if (a[st[start]][st[st.size()-2]] == '1') {
						if (!find1) {
							cout << (st[start]+1) << " " << (st[st.size()-2]+1) << " " << (st[st.size()-1]+1) << endl;
							exit(0);
						}
						find1 = true;
						st.clear();
					} else {
						st.pop_back();
					}
				}
				if ((st.size()-start == 3)&&(!find1)) {
					for (int i = start; i < st.size(); i++)
						cout << (st[i]+1) << " ";
					cout << endl;
					exit(0);
					find1 = true;
				}
			}
		}
	}
	color[k] = 2;
	if (!find1) st.pop_back();
	}
};
//
int main() {
	//freopen("input.txt", "r", stdin);
	//
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
			scanf(" %s", a[i]);
	}
	//
	for (int i = 0; i < n; i++) {
		if ((color[i] == 0)&&(!find1)) dfs(i);
	}
	//
	if (!find1) cout << "-1" << endl;
	//
	return 0;
}