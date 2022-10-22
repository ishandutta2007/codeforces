uses math;

var n,m,p,q     : int64;
    l,r         : longint;
    i,j,k       : longint;
    x,y         : int64;
    cnt,ans     : int64;
    a           : array[1..100] of longint;
    s,s1,s2     : ansistring;
    c           : array[1..5] of char;
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

     c[1] := 'h';
     c[2] := 'e';
     c[3] := 'l';
     c[4] := 'l';
     c[5] := 'o';

     j := 1;

     for i := 1 to length(s) do
     begin
          if s[i] = c[j]
          then inc(j);

          if j = 6 then break;
     end;

     if j = 6 then writeln('YES') else writeln('NO');
end.