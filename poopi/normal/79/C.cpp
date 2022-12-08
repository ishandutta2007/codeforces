   /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
 using namespace std;


 int n, len;
 char in[100010];
 int mx[100010];

 void setMx(string b){
     for(int i = 0; i < len; i++){
         bool fl = true;
         for(int j = 0; j < b.size(); j++)
             if(in[i + j] != b[j])
                 fl = false;
         if(fl && i + (int)b.size() - 1 < mx[i])
             mx[i] = i + b.size() - 1;
     }
 }

 int can(int sz){
     if(sz == 0)
         return 0;
     int str = 0;
     for(int i = 0; i < len; i++){
         if(mx[i] < str + sz)
             str = i + 1;
         else if(i == str + sz - 1)
             return str;
     }
     return -1;
 }

 int main(){
     gets(in);
     len = strlen(in);
     cin >> n;
     string s;
     for(int i = 0; i < len; i++)
         mx[i] = len + 1;
     for(int i = 0; i < n; i++){
         cin >> s;
         setMx(s);
     }
    /* for(int i = 0; i < len; i++)
         cout << mx[i] << ' ';
     cout << endl;*/
     int l = 0, r = len;
     while(l < r){
         int mid = (l + r + 1) / 2;
         //cout << mid << ' ' << l << ' ' << r << ' ' << can(mid) << endl;
         if(can(mid) != -1)
             l = mid;
         else r = mid - 1;
     }
     cout << r << ' ' << can(r) << endl;
    // cin >> n;
     return 0;
 }