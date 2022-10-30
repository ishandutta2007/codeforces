program storm;
var dosk:array[-20..20,-20..20] of char;
    kol,nom1,nom2:longint;


procedure lad(b:char; nom:longint);
var i,j:longint;
begin
 dosk[9-(ord(b)-96),nom]:='*';
 for i:=1 to 8 do
  if dosk[i,nom]<>'*' then dosk[i,nom]:='#';
 for i:=1 to 8 do
  if dosk[(9-(ord(b)-96)),i]<>'*' then dosk[(9-(ord(b)-96)),i]:='#';
end;

procedure kon(b:char; nom:longint);
var nom1,nom2:longint;
begin
 nom1:=9-(ord(b)-96); nom2:=nom;
 dosk[nom1,nom2]:='*';
 dosk[nom1-1,nom2-2]:='#'; dosk[nom1-2,nom2-1]:='#';
 dosk[nom1+1,nom2-2]:='#'; dosk[nom1+2,nom2-1]:='#';
 dosk[nom1+1,nom2+2]:='#'; dosk[nom1+2,nom2+1]:='#';
 dosk[nom1-1,nom2+2]:='#'; dosk[nom1-2,nom2+1]:='#';
end;

procedure outputdata;
begin
 writeln(kol);
end;

procedure inputdata;
var chiclo1,chiclo2,code:longint;
    c1,c2:char;
    s1,s2:string;
begin
 readln(s1);
 readln(s2);
 c1:=s1[1]; c2:=s2[1];
 val(s1[2],chiclo1,code); val(s2[2],chiclo2,code);
 lad(c1,chiclo1);
 kon(c2,chiclo2);
end;

begin
 inputdata; kol:=0;
 for nom1:=1 to 8 do
  for nom2:=1 to 8 do
  if (dosk[nom1,nom2]<>'*') and (dosk[nom1,nom2]<>'#') and (dosk[nom1-1,nom2-2
  ]<>'*') and
   (dosk[nom1-2,nom2-1]<>'*') and (dosk[nom1+1,nom2-2]<>'*') and (dosk[nom1+2,nom2-1]<>'*') and
    (dosk[nom1+1,nom2+2]<>'*') and (dosk[nom1+2,nom2+1]<>'*') and (dosk[nom1-1,nom2+2]<>'*')
     and (dosk[nom1-2,nom2+1]<>'*') then inc(kol);
 outputdata;
end.