s=input()
try:
    st=s.index('[')
    s=s[st:]
    fn=s.rindex(']')
    s=s[:fn]
    st1=s.index(':')
    fn2=s.rindex(':')
    if fn2==st1:
        raise ValueError
    else:
        print(4+s[st1:fn2].count('|'))
except Exception:
    print(-1)