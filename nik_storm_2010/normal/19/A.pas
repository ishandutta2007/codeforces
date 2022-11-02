Program A19;
Var
  nam        : array[1..50] of string;
  score      : array[1..50] of longint;
  get_ball   : array[1..50] of longint;
  miss_ball  : array[1..50] of longint;
  difference : array[1..50] of longint;
  answer : array[1..50] of string;

  nam1,nam2,s1,s2,s : string;
  getball1,getball2,j,code,score1,score2,i,n,kol : longint;


Procedure zamena;
Var szam : string;
    czam : longint;
 Begin
  szam:=nam[j];        nam[j]:=nam[j+1];               nam[j+1]:=szam;
  czam:=score[j];      score[j]:=score[j+1];           score[j+1]:=czam;
  czam:=get_ball[j];   get_ball[j]:=get_ball[j+1];     get_ball[j+1]:=czam;
  czam:=miss_ball[j];  miss_ball[j]:=miss_ball[j+1];   miss_ball[j+1]:=czam;
  czam:=difference[j]; difference[j]:=difference[j+1]; difference[j+1]:=czam;
 End;


BEGIN

  readln(n);
  for i:=1 to n do readln(nam[i]);

  kol:=n*(n-1) div 2;
  for i:=1 to kol do
   begin
    readln(s);
    nam1:=''; j:=1;
    while s[j]<>'-' do
                      begin
                       nam1:=nam1+s[j];
                       inc(j);
                      end;
    nam2:=''; inc(j);
    while s[j]<>' ' do
                      begin
                       nam2:=nam2+s[j];
                       inc(j);
                      end;
    s1:=''; inc(j);
    while s[j]<>':' do
                      begin
                       s1:=s1+s[j];
                       inc(j);
                      end;
    s2:=copy(s,j+1,length(s)-j);

    val(s1,getball1,code);
    val(s2,getball2,code);
    if getball1>getball2 then begin score1:=3; score2:=0; end;
    if getball2>getball1 then begin score1:=0; score2:=3; end;
    if getball1=getball2 then begin score1:=1; score2:=1; end;

    for j:=1 to n do
     begin
      if nam[j]=nam1 then
                         begin
                          inc(score[j],score1);
                          inc(get_ball[j],getball1);
                          inc(miss_ball[j],getball2);
                          difference[j]:=get_ball[j]-miss_ball[j];
                         end;
      if nam[j]=nam2 then
                         begin
                          inc(score[j],score2);
                          inc(get_ball[j],getball2);
                          inc(miss_ball[j],getball1);
                          difference[j]:=get_ball[j]-miss_ball[j];
                         end;
     end;

   end;

  for i:=1 to n-1 do
   for j:=1 to n-i do
    if score[j]>score[j+1] then zamena else
     if (score[j]=score[j+1]) and (difference[j]>difference[j+1]) then zamena else
      if (score[j]=score[j+1]) and (difference[j]=difference[j+1]) and (get_ball[j]>get_ball[j+1]) then zamena;

  for i:=n div 2 + 1 to n do answer[i-(n div 2)]:=nam[i];

  n:=n div 2;
  for i:=1 to n-1 do
   for j:=1 to n-i do
    if answer[j]>answer[j+1] then
     begin
      s:=answer[j];
      answer[j]:=answer[j+1];
      answer[j+1]:=s;
     end;

  for i:=1 to n do writeln(answer[i]);

END.