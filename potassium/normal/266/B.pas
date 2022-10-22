uses math;
const inf = 2147483647;
var n,m,p,q,t   : longint;
    l,r         : longint;
    i,j,k       : longint;
    x,y,z       : longint;
    cnt,ans     : int64;
    a           : array[1..3] of longint;
    s,s1,s2     : ansistring;
    c           : char;
    b           : boolean;

procedure swap (var a,b : longint);var t : longint;begin t := a;a := b;b := t;end;
procedure swapc(var a,b : char)   ;var t : char;   begin t := a;a := b;b := t;end;

begin
     readln(n,t);

     readln(s);

     for i := 1 to t do
     begin
          j := 1;
          while j < length(s) do
          begin
               if (s[j] = 'B') AND (s[j+1] = 'G')
               then begin
                         swapc(s[j],s[j+1]);
                         inc(j);
                    end;
               inc(j);
          end;
     end;

     writeln(s);
end.