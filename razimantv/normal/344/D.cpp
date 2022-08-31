# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>
# include <map>
# include <stack>

using namespace std;

char inp[1000000];
stack<char> rem;

int main()
{
  scanf("%s",inp);
  for(int i=0;inp[i];i++)
  {
    if((!rem.empty())&&(rem.top()==inp[i]))rem.pop();
    else rem.push(inp[i]);
  }
  printf("%s\n",rem.empty()?"Yes":"No");
  return 0;
}