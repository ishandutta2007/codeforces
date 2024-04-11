//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
 
bool f = true;

bool letter(char c)
{
 if (c>='a' && c<='z') return true;
 return false;
};

void printw(string s)
{
 if (f) 
 { printf("%s",s.c_str());
 f = false; } else
 printf(" %s",s.c_str());
};

int main() {
        char c;
        string s = ""; char last='a';
        while (scanf("%c",&c)==1)
        {
            if (!letter(last) && letter(c)) { printw(s); s = c; last = c; continue; }
            if (c!=' ') s+=c; last = c;       
        }
        if (!s.empty()) printw(s);
        return 0;
}