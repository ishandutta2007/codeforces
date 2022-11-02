var
  a,b : array[1..10] of longint; sys:array[1..100] of boolean;
   s1, s2, s : string; wr:boolean;
    i, d1, d2, t1, t2,x1,x2 : longint;


procedure c(nom:longint; var time:longint);
var i,tek:longint;
 begin
  tek:=1; time:=0;
   for i:=1 to d1 do
    if a[i]>=nom
     then
      begin
       time:=-1;
       exit;
      end
     else
      begin
       time:=time+a[i]*tek;
        tek:=tek*nom;
      end;
 end;


procedure v(nom:longint; var time:longint);
var i,tek:longint;
 begin
  tek:=1; time:=0;
   for i:=1 to d2 do
    if b[i]>=nom
     then
      begin
       time:=-1;
       exit;
      end
     else
      begin
       time:=time+b[i]*tek;
        tek:=tek*nom;
      end;
 end;



begin

  readln(s); s:=s+'$';
   i:=1; s1:=''; s2:='';
    while s[i] <> ':' do
     begin
      s1:=s1+s[i];
      inc(i);
     end;
   inc(i);
    while s[i] <> '$' do
     begin
      s2:=s2+s[i];
      inc(i);
     end;

   d1:=length(s1);
    for i:=d1 downto 1 do
     begin
      if ord(s1[i])>=65
       then
        begin
         a[d1-i+1]:=ord(s1[i])-55;
        end
       else
        begin
         a[d1-i+1]:=ord(s1[i])-48;
        end;
     end;
   d2:=length(s2);
    for i:=d2 downto 1 do
     begin
      if ord(s2[i])>=65
       then
        begin
         b[d2-i+1]:=ord(s2[i])-55;
        end
       else
        begin
         b[d2-i+1]:=ord(s2[i])-48;
        end;
     end;

  wr:=false;
    for i:=2 to 1000 do
      begin
       c(i,t1); v(i,t2);
        if (t1=-1) or (t2=-1) then continue;
         if (t1<=23) and (t2<=59)
          then
           begin
            sys[i]:=true;
            wr:=true;
           end
          else
           begin
            if (t1>23) or (t2>59) then break;
           end;
       if (i=70) then begin writeln(-1); halt; end;
      end;
  for i:=1 to 60 do if sys[i]=true then write(i,' ');
  if wr=false then write(0);

end.