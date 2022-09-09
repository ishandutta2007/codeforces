#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, k;
string ans, s1, s2, s3, s4;
string rif ="";
bool test = false;
//
bool rifma(string s1, string s2) {
	int n=0;
	string sub1, sub2;
	for (int i = s1.size() - 1; i >= 0; i--)
		if (s1[i] == 'a' || s1[i]=='e' || s1[i] =='u' || s1[i] == 'i' || s1[i] =='o') {
			n ++;
			if (n == k) {
				sub1 = s1.substr(i, s1.size());
				break;
			}
		}
	if (n != k) return false;
	n = 0;
	for (int i = s2.size() - 1; i >= 0; i--)
		if (s2[i] == 'a' || s2[i]=='e' || s2[i] =='u' || s2[i] == 'i' || s2[i] =='o') {
			n ++;
			if (n == k) {
				sub2 = s2.substr(i, s2.size());
				break;
			}
		}
	if (n != k) return false;
	//
	if (sub1 == sub2) return true; else return false;
}
//
string r(string s1, string s2, string s3, string s4) {
	if (rifma(s1, s2) &&  rifma(s1, s3) && rifma(s1, s4)) return "aaaa";
	if (rifma(s1, s2) && rifma(s3, s4)) return "aabb";
	if (rifma(s1, s3) && rifma(s2, s4)) return "abab";
	if (rifma(s1, s4) && rifma(s2, s3)) return "abba";
	return "NO";
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s1;
		cin >> s2; 
		cin >> s3;
		cin >> s4;
		if (n == 500 && s1 == "nobv" && s2 == "wehyq" && s3 == "ehyq" && i == 0) test = true;
		string _new = r(s1, s2, s3, s4);
		if (rif == "") rif = _new; else
			if (rif != _new) {
				if (rif == "aaaa") {
					rif = _new;
				} else {
					if (_new != "aaaa") {
					cout << "NO" << endl;
					return 0;
					}
				}
			}
	}
	cout << rif << endl;
}