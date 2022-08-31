#include <iostream>
 
using namespace std;
 
int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        char s1[n];
        char s2[n];
        char s3[n];
        s1[0] = 'R';
        s2[0] = 'G';
        s3[0] = 'B';
        for(int j = 1; j < n; j++) {
            s1[j] = s2[j - 1];
            s2[j] = s3[j - 1];
            s3[j] = s1[j - 1];
        }
        
        int counter1 = 0;
        int counter2 = 0;
        int counter3 = 0;
        
        int myMin = k;
        
        for(int l = 0; l < k; l++) {
            if(s[l] != s1[l]) {
                counter1++;
            }
            if(s[l] != s2[l]) {
                counter2++;
            }
            if(s[l] != s3[l]) {
                counter3++;
            }
        }
        
          
        myMin = min(myMin, min(counter1, min(counter2, counter3)));
      
      
        int count1 = 0;
     
        for(int j = 0; j < n - k; j++) {
        
        	
            if(s[j] != s1[j]) {
                counter1--;
            }
            if(s[k + j] != s1[j+k]) {
                counter1++;
            }
            if(s[j] != s2[j]) {
                counter2--;
            }
            if(s[k + j] != s2[k+j]) {
                counter2++;
            }
            if(s[j] != s3[j]) {
                counter3--;
            }
            if(s[k + j] != s3[k+j]) {
                counter3++;
            }
            
            myMin = min(myMin, min(counter1, min(counter2, counter3)));
        }
        cout << myMin << endl;
    }
    return 0;
}