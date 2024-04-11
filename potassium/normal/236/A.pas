uses math;

var n,m,p,q     : int64;
    l,r         : longint;
    i,j,k       : longint;
    x,y         : int64;
    cnt,ans     : int64;
    a           : array['a'..'z'] of boolean;
    s,s1,s2     : ansistring;
    c           : char;
    b           : boolean;

procedure swap(var a,b : longint);

var t : longint;

begin
     t := a;
     a := b;
     b := t;
end;

begin
     readln(s);

     for i := 1 to length(s) do
         a[s[i]] := TRUE;

     cnt := 0;

     for c := 'a' to 'z' do
         if a[c] = TRUE
         then inc(cnt);

     if cnt mod 2 = 0
     then writeln('CHAT WITH HER!')
     else writeln('IGNORE HIM!');
end.