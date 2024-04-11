#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
  int n, a, ptr, x, c;
  char b;
  cin >> n;
  a=0;
  if(n<=10000){
        string s="bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        ptr=100;
        while(a<n){
            if(s[ptr]=='a' && ptr>0){
                if(s[ptr-1]=='b'){
                    b=s[ptr];
                    s[ptr]=s[ptr-1];
                    s[ptr-1]=b;
                    a++;
                    ptr--;
                }

                else ptr++;
            }
            else ptr++;
        }
        cout << s << " " << "ab";
  }

else{
     int delitele[1000000];
     fill(delitele, delitele + 1000000, 1);


    for(int i=6; i<1550; i++){
     a=i;
     while(a<1000000){
         delitele[a]=i;
         a+=i;

     }
    }

    int cisla[1000000][3];

    for(int i=0; i<1000000; i++){
        cisla[i][0]=0;
    }

    for(int i=1; i<1000000; i++){
            if(delitele[i]<1550 && i/delitele[i]<1550){

                cisla[i][0]=1;
                cisla[i][1]=max(delitele[i], i/delitele[i]);
                cisla[i][2]=min(delitele[i], i/delitele[i]);

            }

    }

    string s="abc";
    x=n-40;
    while(cisla[x][0]==0){
        x--;
        s.push_back('d');
        }

    for(int i=0; i<39; i++){
        s.push_back('b');
    }

    for(int i=0; i<39; i++){
        s.push_back('a');
    }

    for(int i=0; i<40; i++){
        s.push_back('d');
    }

    for(int i=0; i<40; i++){
        s.push_back('c');
    }

    a=0;
    ptr=0;
    while(a<cisla[x][1]-40){
            if(s[ptr]=='a' && ptr>0){
                if(s[ptr-1]=='b'){
                    b=s[ptr];
                    s[ptr]=s[ptr-1];
                    s[ptr-1]=b;
                    a++;
                    ptr--;
                }

                else ptr++;
            }
            else ptr++;
        }

    a=0;
    ptr=0;
    while(a<cisla[x][2]){
            if(s[ptr]=='c' && ptr>0){
                if(s[ptr-1]=='d'){
                    b=s[ptr];
                    s[ptr]=s[ptr-1];
                    s[ptr-1]=b;
                    a++;
                    ptr--;
                }

                else ptr++;
            }
            else ptr++;
        }


    cout << s << " " << "abcd";

  }


  return 0;
}