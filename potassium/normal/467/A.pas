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
     readln(n);

     cnt := 0;

     for i := 1 to n do
     begin
          readln(l,r);

          if (r-l >= 2)
          then inc(cnt);
     end;

     writeln(cnt);
end.