var
   d1,d2,leng,n,kol1,kol2,kol,ans1,ans2:longint;
    s1,s2:ansistring;


procedure nok(a,b:longint; var c:longint);
var i,j:longint;
 begin
  i:=a; j:=b;
   while (a>0) and (b>0) do
    if a>b then a:=a mod b
   else b:=b mod a;
  c:=(i*j) div (a+b);
 end;


procedure prov(leng:longint; var a,b:longint);
var i,j:longint;
 begin
  i:=1; j:=1; a:=0; b:=0;
  while leng<>0 do
   begin
    if ((s1[i]='R') and (s2[j]='S')) or ((s1[i]='S') and (s2[j]='P'))
     or ((s1[i]='P') and (s2[j]='R')) then inc(a);
    if ((s1[i]='S') and (s2[j]='R')) or ((s1[i]='P') and (s2[j]='S'))
     or ((s1[i]='R') and (s2[j]='P')) then inc(b);

    inc(i); if i>d1 then i:=1;
     inc(j); if j>d2 then j:=1;
    dec(leng);
   end;
 end;


begin

  readln(n);
   readln(s1);
  readln(s2);

  d1:=length(s1); d2:=length(s2);
   nok(d1,d2,leng);
    kol:=n div leng;
   prov(leng,kol1,kol2);
  ans1:=kol1*kol; ans2:=kol2*kol;

  prov(n-kol*leng,kol1,kol2);
   ans1:=ans1+kol1; ans2:=ans2+kol2;
  writeln(ans2,' ',ans1);

end.