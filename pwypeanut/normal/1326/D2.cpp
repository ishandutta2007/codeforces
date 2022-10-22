#include <bits/stdc++.h>
using namespace std;


int findLongestPalindromicString(const char *text) 
{ 
    int N = strlen(text); 
    if(N == 0) 
        return 0; 
    N = 2*N + 1; //Position count 
    int L[N]; //LPS Length Array 
    L[0] = 0; 
    L[1] = 1; 
    int C = 1; //centerPosition  
    int R = 2; //centerRightPosition 
    int i = 0; //currentRightPosition 
    int iMirror; //currentLeftPosition 
    int maxLPSLength = 0; 
    int maxLPSCenterPosition = 0; 
    int start = -1; 
    int end = -1; 
    int mx = 1;
    int diff = -1; 
     // printf("%s\n", text);
    //Uncomment it to print LPS Length array 
    //printf("%d %d ", L[0], L[1]); 
    for (i = 2; i < N; i++)  
    { 
        //get currentLeftPosition iMirror for currentRightPosition i 
        iMirror  = 2*C-i; 
        L[i] = 0; 
        diff = R - i; 
        //If currentRightPosition i is within centerRightPosition R 
        if(diff > 0) 
            L[i] = min(L[iMirror], diff); 
  
        //Attempt to expand palindrome centered at currentRightPosition i 
        //Here for odd positions, we compare characters and  
        //if match then increment LPS Length by ONE 
        //If even position, we just increment LPS by ONE without  
        //any character comparison 
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&  
            ( ((i + L[i] + 1) % 2 == 0) ||  
            (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))) 
        { 
            L[i]++; 
        } 
  
        if(L[i] > maxLPSLength)  // Track maxLPSLength 
        { 
            maxLPSLength = L[i]; 
            maxLPSCenterPosition = i; 
        } 
  
        //If palindrome centered at currentRightPosition i  
        //expand beyond centerRightPosition R, 
        //adjust centerPosition C based on expanded palindrome. 
        if (i + L[i] > R)  
        { 
            C = i; 
            R = i + L[i]; 
        } 
        //Uncomment it to print LPS Length array 
        if (L[i] == i) {
			mx = max(mx, L[i]);
		}
		//printf("%d %d\n", L[i], i);
    } 
    return mx;
} 



int tc;
char c[1000005];
string s;

string attempt(string s) {
	string whack = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s[s.length() - i - 1]) {
			whack += s[i];
		} else break;
	}
	if (whack.length() == s.length()) return whack;
	string newval = "";
	for (int i = whack.length(); i < s.length() - whack.length(); i++) newval += s[i];
	int get = findLongestPalindromicString(newval.c_str());
	string ans = whack;
	for (int i = whack.length(); i < whack.length() + get; i++) ans += s[i];
	for (int i = whack.length() - 1; i >= 0; i--) ans += whack[i];
	return ans;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", c);
		s = string(c);
		string f = attempt(s);
		reverse(s.begin(), s.end());
		string b = attempt(s);
		reverse(b.begin(), b.end());
		if (f.length() > b.length()) printf("%s\n", f.c_str());
		else printf("%s\n", b.c_str());
	}
}