#include <iostream>

#define N 210

using namespace std;

string in[N], out[N];
int w, h;

int main() {
	cin >> w >> h;
	for(int i = 0;i < h;i++) {
		cin >> in[i];
	}
	for(int i = 0;i < 2*w;i++) {
		out[i].resize(2*h, 0);
	}
	for(int i = 0;i < h;i++) {
		for(int j = 0;j < w;j++) {
			out[j][i] = in[i][j];
		}
	}
	for(int i = 0;i < w;i++) {
		for(int k = 0;k < 2;k++) {
			for(int j = 0;j < h;j++) {
				for(int kk = 0;kk < 2;kk++) {
					cout << out[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}