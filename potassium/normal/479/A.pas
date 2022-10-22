uses math;

const inf = 2147483647;

var n,m,p,q,t   : longint;
    l,r         : longint;
    i,j,k       : longint;
    x,y,z       : longint;
    cnt,ans     : int64;
    a           : array[1..1048575] of longint;
    s,s1,s2     : ansistring;
    c           : char;
    b           : boolean;

    depth       : longint;
    fn          : longint;

procedure swap (var a,b : longint);var t : longint;begin t := a;a := b;b := t;end;
procedure swapc(var a,b : char)   ;var t : char;   begin t := a;a := b;b := t;end;

function gcd  (a,b : longint):longint;var t : longint;begin while a > 0 do begin t := a;a := b mod a;b := t;end;gcd := b;end;

begin
     readln(x);
     readln(y);
     readln(z);

     cnt := 0;

     for i := 1 to 2 do
     begin
          for j := 1 to 2 do
          begin
               for k := 1 to 2 do
               begin
                    if i = 1
                    then begin
                              if j = 1
                              then ans := x+y
                              else ans := x*y;
                              if k = 1
                              then ans := ans + z
                              else ans := ans * z;
                         end
                    else begin
                              if k = 1
                              then ans := y+z
                              else ans := y*z;
                              if j = 1
                              then ans := ans + x
                              else ans := ans * x;
                         end;
                         cnt := max(cnt,ans);
               end;
          end;
     end;

     writeln(cnt);
end.