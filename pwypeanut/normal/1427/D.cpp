#include <bits/stdc++.h>
using namespace std;

int N, A[53];
vector< vector<int> > seqs;

void split_seqs() {
	seqs.clear();
	vector<int> V;
	for (int i = 0; i < N; i++) {
		if (i != 0 && A[i] != A[i - 1] + 1) {
			seqs.push_back(V);
			V.clear();
			V.push_back(A[i]);
		} else V.push_back(A[i]);
	}
	seqs.push_back(V);
}

vector< vector<int> > answer;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	
	while (1) {
		split_seqs();
		if (seqs.size() == 1) break;
		int a = -1, b = -1;
		for (int i = 0; i < seqs.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (seqs[i].back() + 1 == seqs[j][0]) {
					b = i;
					a = j;
					break;
				}
			}
		}
		assert(a != -1 && b != -1);
		vector<int> values;
		for (int i = 0; i < a; i++) values.push_back(seqs[i].size());
		int sum = 0;
		for (int i = a; i < b; i++) sum += seqs[i].size();
		values.push_back(sum);
		for (int i = b; i < seqs.size(); i++) values.push_back(seqs[i].size());
		
		answer.push_back(values);
		
		int l = 0;
		seqs.clear();
		for (int i = 0; i < values.size(); i++) {
			int r = l + values[i];
			vector<int> V;
			for (int j = l; j < r; j++) V.push_back(A[j]);
			seqs.push_back(V);
			l = r;
		}
		reverse(seqs.begin(), seqs.end());
		int cnt = 0;
		for (int i = 0; i < seqs.size(); i++) {
			for (int j = 0; j < seqs[i].size(); j++) {
				A[cnt] = seqs[i][j];
				cnt++;
			}
		}
		seqs.clear();
	}
	printf("%d\n", answer.size());
	for (int j = 0; j < answer.size(); j++) {
		printf("%d", answer[j].size());
		for (int i = 0; i < answer[j].size(); i++) printf(" %d", answer[j][i]);
		printf("\n");
	}
}