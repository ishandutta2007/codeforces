Var
    a:array[97..122,0..100000] of longint;
     n,k,fun,leng,tek: int64;
      i,j: longint;
       st: ansistring;
         s: char;


procedure dix(nom,c:longint; var t:int64);
var l,r,middle:longint;
 begin
  l:=1;
   r:=a[nom,0];
    while r-l > 1 do
     begin
      middle:=a[nom,(r+l) div 2];
       if middle > c then r:=(r+l) div 2 else l:=(r+l) div 2;
     end;
  t:=MaxLongint;
   if (abs(c-a[nom,l])<t) and (r>=l) then t:=abs(c-a[nom,l]);
    if (abs(c-a[nom,r])<t) and (r>=l) then t:=abs(c-a[nom,r]);
 end;


Begin

  readln(n,k);
   for i:=1 to k do
    begin
     read(s);
      inc(a[ord(s),0]);
       a[ord(s),a[ord(s),0]]:=i;
    end;
  readln;
   for i:=1 to n do
    begin
     fun:=0;
      readln(st);
       leng:=length(st);
        for j:=1 to leng do
         begin
          dix(ord(st[j]),j,tek);
           if tek = MaxLongint then inc(fun,leng) else inc(fun,tek);
         end;
     writeln(fun);
    end;

End.