#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, f[200001], received[200001];
vector<int> unsure, notReceived, notReceivedCopy;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		received[i]=0;
	for (int i=1; i<=n; ++i) {
		cin >> f[i];
		if (f[i] == 0)
			unsure.push_back(i);
		else
			received[f[i]]=1;
	}
	for (int i=1; i<=n; ++i) {
		if (received[i]==0) {
			notReceived.push_back(i);
			notReceivedCopy.push_back(i);
		}
	}

	bool processed[200000];
	for (int i=0; i<unsure.size(); ++i)
		processed[i] = 0;
	int cnt = 0;	
	//for (int i=0; i<unsure.size(); ++i)
	//	cout << unsure[i] << ' ' << notReceived[i] << '\n';

	for (int i=0; i<unsure.size(); ++i) {
		while (processed[cnt])
			cnt++;
		if (i != unsure.size()-1) {
			if (unsure[i] != notReceived[cnt]) {
				f[unsure[i]] = notReceived[cnt];
				processed[cnt]=1;
			}
			else {
				f[unsure[i]] = notReceived[cnt+1];
				processed[cnt+1]=1;
			}
		}
		else if (unsure[i] == notReceived[cnt]){
			for (int j=0; j<unsure.size()-1; ++j) {
				if (unsure[i] != f[notReceivedCopy[j]] && unsure[j] != notReceived[cnt]) {
					f[unsure[i]] = f[unsure[j]];
					f[unsure[j]] = notReceived[cnt];
					break;
				}
			}
		}
		else {
			f[unsure[i]] = notReceived[cnt];
		}
	}
	
	for (int i=1; i<=n; ++i)
		cout << f[i] << ' ';
	cout << '\n';
	return 0;
}