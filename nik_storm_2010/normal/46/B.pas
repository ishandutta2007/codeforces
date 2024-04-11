program storm;
var a:array[-10..100] of longint;
    vyv:array[1..1005] of string;
    s,s1:string;
    n,nom:longint;


procedure poisk(nom:longint; var nom1:longint; var s:string);
var tek,i:longint;
begin
 tek:=1; i:=nom;
 while (a[i]=0) do
   begin
    if tek mod 2 = 1 then inc(i,tek)
                     else dec(i,tek);
    inc(tek);
   end;
 nom1:=i;
 if nom1=1 then s:='S';  if nom1=2 then s:='M'; if nom1=3 then s:='L';
 if nom1=4 then s:='XL'; if nom1=5 then s:='XXL';
end;

procedure inputdata;
var i:longint;
begin
 readln(a[1],a[2],a[3],a[4],a[5]);
 readln(n);
 for i:=1 to n do
  begin
   readln(s);
   if s='S'   then begin poisk(1,nom,s1); dec(a[nom]); vyv[i]:=s1; end;
   if s='M'   then begin poisk(2,nom,s1); dec(a[nom]); vyv[i]:=s1; end;
   if s='L'   then begin poisk(3,nom,s1); dec(a[nom]); vyv[i]:=s1; end;
   if s='XL'  then begin poisk(4,nom,s1); dec(a[nom]); vyv[i]:=s1; end;
   if s='XXL' then begin poisk(5,nom,s1); dec(a[nom]); vyv[i]:=s1; end;
  end;
end;

procedure outputdata;
var i:longint;
begin
 for i:=1 to n do writeln(vyv[i]);
end;

begin
 inputdata;
 outputdata;
end.