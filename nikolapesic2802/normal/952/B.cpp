#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    set<string> norm = {"no", "dont think so", "great", "not bad", "cool", "dont touch me"};
    set<string> gr = {"no", "dont even", "worse", "terrible", "are you serious", "go die in a hole", "no way"};
    for(int i=0;i<=9;i++)
    {
        printf("%i\n",i);
        string s;
        getline(cin,s);
        if (norm.count(s) && !gr.count(s)) {
            printf("normal\n");
            return 0;
        }
        if (!norm.count(s) && gr.count(s)) {
            printf("grumpy\n");
            return 0;
        }
    }
    return 0;
}