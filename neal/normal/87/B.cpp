#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

enum TYPE {VOID, ERRTYPE};

struct type_class
{
    TYPE type;
    int stars;

    type_class (TYPE _type = ERRTYPE, int _stars = 0)
    {
        type = _type;
        stars = _stars;
    }

    void add (int _stars)
    {
        stars += _stars;

        if (stars < 0)
            type = ERRTYPE;
    }

    string to_string ()
    {
        if (type == ERRTYPE)
            return "errtype";
        else
            return "void" + string (stars, '*');
    }
};

map <string, type_class> mapping;
int N;

inline type_class parse (string s)
{
    int a = 0, b = s.length () - 1;
    int ac = 0, bc = 0;

    while (s [a] == '&')
    {
        a++;
        ac++;
    }

    while (s [b] == '*')
    {
        b--;
        bc++;
    }

    s = s.substr (a, b + 1 - a);

    if (mapping.find (s) == mapping.end ())
        return type_class (ERRTYPE, 0);
    else
    {
        type_class t = mapping [s];
        t.add (bc - ac);
        return t;
    }
}

int main ()
{
    mapping ["void"] = type_class (VOID, 0);
    mapping ["errtype"] = type_class (ERRTYPE, 0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string a, b, c;
        cin >> a;

        if (a == "typedef")
        {
            cin >> b >> c;
            mapping [c] = parse (b);
        }
        else if (a == "typeof")
        {
            cin >> b;
            cout << parse (b).to_string () << '\n';
        }
    }

    return 0;
}