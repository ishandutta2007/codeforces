#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//
int n, m;
string s1;
//
vector <string> pazles;
vector <string> s;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s1;
		s.push_back(s1);
	}
	//
	int sum = 0; 
	int answ_x= 10000;
	int answ_y = 10000;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if ((n %x ==0) && (m %y ==0) ){
				pazles.clear();
				for (int x1= 0; x1 < n/x; x1++) {
					for (int y1=0 ; y1< m/y; y1++) {
						string s1="";
						for (int x11=x1*(x); x11 < (x1+1)*(x); x11++) {
							s1+=s[x11].substr(y1*y, y);
						}
						pazles.push_back(s1);
						//
						string s1r = s1;
						reverse(s1r.begin(), s1r.end());
						if (s1r != s1) {
							pazles.push_back(s1r);
						}
						if (x == y) {
						string s2="";
						for (int y11 = (y1+1)*y-1; y11 >= (y1)*y; y11--) {
							for (int x11=x1*(x); x11 < (x1+1)*(x); x11++) {
								s2+=s[x11].substr(y11, 1);
							}
						}
						if ((s2 != s1) && (s2 != s1r)) {
							pazles.push_back(s2);
						}
						string s2r = s2;
						reverse(s2r.begin(), s2r.end());
						if ((s2r != s2) && (s2r != s1) && (s2r != s1r)) {
							pazles.push_back(s2r);
						}
						}
					}
				}
				//
				sort(pazles.begin(), pazles.end());
				bool ok = true;
				for (int i = 0; i < pazles.size()-1; i++) 
					if (pazles[i] == pazles[i+1]) ok = false;
				if (ok) {
					//cout << x << " "<< y << endl;
					sum++;
					if ((x*y < answ_x*answ_y)||((x*y==answ_x*answ_y) && (x < answ_x))) {
						answ_x = x;
						answ_y = y;
					}
				}
			}
		}
	}
	cout << sum << endl;
	cout << answ_x << " " << answ_y << endl;
	//
	return 0;
}