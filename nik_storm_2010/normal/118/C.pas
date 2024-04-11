Var
    a: array[1..10000] of longint;
     kol: array[-20..20] of longint;
      t: array[0..9] of longint;
       n,m,i,answer,error,c,leng,j,lack,k,presentsum: longint;
        s1,sanswer,stek: ansistring;


procedure st(var sanswer:ansistring);
var i:longint;
     s,ss:ansistring;
 begin
  s:=s1;
  for i:=1 to leng do
    begin
     val(s[i],c,error);
      if (c>t[0]) and (t[abs(t[0]-c)]<>0)
       then
        begin
         str(t[0],ss);
          s[i]:=ss[1];
           dec(t[abs(t[0]-c)]);
        end;
    end;
   sanswer:='';
   for i:=leng downto 1 do
    begin
     val(s[i],c,error);
      if (t[abs(t[0]-c)]<>0) and (c<>t[0])
       then
        begin
         dec(t[abs(t[0]-c)]);
          str(t[0],ss);
           sanswer:=ss[1]+sanswer;
        end
       else
        begin
         sanswer:=s[i]+sanswer;
        end;
    end;
 end;

Begin

  readln(n,k);
   readln(s1);
    leng:=length(s1);
     for i:=1 to leng do
      begin
       val(s1[i],c,error);
        inc(kol[c]);
      end;

 answer:=MaxLongint; sanswer:='A';
  for i:=0 to 9 do
   begin
    lack:=k-kol[i];
    j:=1;
     presentsum:=0;
      fillchar(t,sizeof(t),0); t[0]:=i;
       while lack>0 do
        begin
         m:=kol[i+j]+kol[i-j];
          if m>lack
           then
            begin
             presentsum:=presentsum+lack*j;
              inc(t[j],lack);
               lack:=0;
            end
           else
            begin
             presentsum:=presentsum+m*j;
              lack:=lack-m;
               inc(t[j],m);
            end;
         inc(j);
        end;
    st(stek);
     if ((presentsum < answer) and (presentsum>=0)) or ((presentsum=answer) and (stek<sanswer))
      then
       begin
        answer:=presentsum;
         sanswer:=stek;
       end;
   end;
  writeln(answer);
   writeln(sanswer);

End.